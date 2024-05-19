/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/19 16:02:34 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colours.hpp"

//https://www.geeksforgeeks.org/cpp-polymorphism/

int main(void)
{
	std::cout << std::endl << "Bureaucrat Pen, 1" << std::endl;
	try
	{
		Bureaucrat	pen("Pen", 1);
		std::cout << pen << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Bureaucrat Zero, 0" << std::endl;
	try
	{
		Bureaucrat	zero("Zero", 0);
		std::cout << zero << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Bureaucrat Sparta, 300" << std::endl;
	try
	{
		Bureaucrat	sparta("Sparta", 300);
		std::cout << sparta << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Bureaucrat Ink - increment test, 2" << std::endl;
	try
	{
		Bureaucrat ink("Ink", 2);
		std::cout << ink << std::endl;
		ink.increment();
		std::cout << ink << std::endl;
		ink.increment();
		std::cout << ink << std::endl;
		ink.increment();
		std::cout << ink << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Bureaucrat dec - decrement test, 148" << std::endl;
	try
	{
		Bureaucrat dec("dec", 148);
		std::cout << dec << std::endl;
		dec.decrement();
		std::cout << dec << std::endl;
		dec.decrement();
		std::cout << dec << std::endl;
		dec.decrement();
		std::cout << dec << std::endl;
		dec.decrement();
		std::cout << dec << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	//forms
	std::cout << std::endl << "Form Norm, 50, 100" << std::endl;
	try
	{
		Form	norm("Norm", 50, 100);
		std::cout << norm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Form high, 0, 100" << std::endl;
	try
	{
		Form	high("High", 0, 100);
		std::cout << high << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Form Low, 50, 200" << std::endl;
	try
	{
		Form	low("Low", 50, 200);
		std::cout << low << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// signing forms
	std::cout << std::endl << "Form Norm, 50, 100, Bureaucrat TF, 25" << std::endl;
	try
	{
		Form		norm("Norm", 50, 100);
		std::cout << norm << std::endl;
		Bureaucrat	tf("tf", 25);
		std::cout << tf << std::endl;
		tf.signForm(norm);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}