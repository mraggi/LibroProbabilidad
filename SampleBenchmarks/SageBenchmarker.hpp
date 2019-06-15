#pragma once

#include "VectorHelpers.hpp"
#include "NaturalNumber.hpp"
#include "rang.hpp"
#include "TimeHelpers.hpp"
#include "Random.hpp"
#include "pcg.hpp"
#include <vector>
#include <map>
#include <string>

std::string without_spaces(const std::string& s)
{
    std::string str = s;
	for (char& c : str)
	{
		if ('0' <= c && c <= '9')
			continue;
		if ('a' <= c && c <= 'z')
			continue;
		if ('A' <= c && c <= 'Z')
			continue;
		c = '_';
	}
	return str;
}

double to_percent(double x, double a, double b)
{
    return (x-a)/(b-a)*100.0;
}
	
std::string random_color()
{
    Random<pcg> random;
    std::string color = "(";
    color += std::to_string(random.random_real(0,0.8)) + ", " + std::to_string(random.random_real(0,0.8)) + ", " + std::to_string(random.random_real(0,0.8)) + ")";
    return color;
}
	
class SageBenchmarker
{
public:
	inline static const double nanoseconds { 1000000000.0 };
	inline static const double microseconds { 1000000.0 };
	inline static const double milliseconds { 1000.0 };
	inline static const double seconds { 1.0 };
	
	explicit SageBenchmarker(int from, int to, int num_steps = 30) : from_(from), to_(to), num_steps_(num_steps) 
    {
    }
	
	template <class Func>
	void add_benchmark(std::string name, Func f)
	{
		names_.emplace_back(name);
		varnames_.emplace_back(without_spaces(name));
        if (names_.size() > color_.size())
            color_.emplace_back(random_color());
		std::cout << without_spaces(name)  << " = [";
		
        int step = step_size();
		for (int i = from_; i < to_; i += step)
		{
			if (i != from_)
				std::cout << ", ";
// 			std::cout << "i =" << i << std::endl;
			Chronometer C;
			int num = num_repeats_;
			if (num_repeats_ >= 0)
			{
				for (int w = 0; w < num_repeats_; ++w)
				{
					f(i);
				}
			} else
			{
				num = 0;
				while (C.Peek() < max_allowed_time_per_benchmark_)
				{
					f(i);
					++num;
				}
			}
			double t = C.Peek()*time_unit_/num;
            if (ymax_ < t)
                ymax_ = t;
			print_time(to_percent(i,from_,to_),t);
		}
		std::cout << ']' << std::endl;
	}

	void set_num_repeats(int num) { num_repeats_ = num; }
	void set_time_unit(double unit) { time_unit_ = unit; }
	void set_max_time(double in_seconds) { max_allowed_time_per_benchmark_ = in_seconds; num_repeats_ = -1; }
	void set_colors(std::vector<std::string> new_colors)
	{
		color_ = std::move(new_colors);
	}
	
	void print_plot_commands() const
	{
		for (int i = 0; i < names_.size(); ++i)
		{
            if (i == 0)
                std::cout << "\n\nP = line(";
            else
                std::cout << "P += line(";
			std::cout << varnames_[i] << ", color=" << color_[i] << ", thickness=1,legend_label=\"" << names_[i] << "\",legend_color=" << color_[i] << ")\n";
		}
		std::cout << std::endl;
		
		for (int i = 0; i < names_.size(); ++i)
		{
			std::cout << "P += sum([point2d(c,size=20,color=" << color_[i] << ") for c in " << varnames_[i] << "])\n";
		}
		std::cout << "\nP.show(dpi=300,frame=True,axes=False,ymax=" << ymax_ << ",\n\t\taxes_labels=(\"sample %\", \""<<unit_string(time_unit_)<<"\"),axes_labels_size=1.0,\n\t\tfontsize=10,show_legend=True)\n";
		std::cout << std::endl;
	}
	
	void set_ymax(double new_ymax) { ymax_ = new_ymax; }
	
private:
	int from_; 
	int to_;
    int num_steps_;
	int num_repeats_{-1}; // -1 means "figure it out yourself!"
    double ymax_ {0.};
	std::vector<std::string> color_ {{"\"red\"", "\"green\"", "\"blue\"", "\"magenta\"", "\"cyan\"", "\"orange\"", "\"brown\"", "\"black\""}};
	std::vector<std::string> names_;
	std::vector<std::string> varnames_;
	
	double time_unit_ { milliseconds };
	double max_allowed_time_per_benchmark_ { 0.2 }; //in seconds!!
	
	void print_time(double i, double t)
	{
		std::cout << '(' << i << ',' << t << ')';
	}
	
	std::string unit_string(double t) const
	{
		if (t == seconds)
			return "seconds";
		if (t == milliseconds)
			return "milliseconds";
		if (t == microseconds)
			return "microseconds";
		if (t == nanoseconds)
			return "nanoseconds";
		return std::to_string(1.0/t) + "ths of a second";
	}
	
	int step_size() const { return std::max(1,(to_-from_)/num_steps_); }
};



