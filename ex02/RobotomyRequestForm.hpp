/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/19 18:00:34 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		const std::string		_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& c);
		~RobotomyRequestForm(void);

		RobotomyRequestForm(const std::string target);

		void	execute(Bureaucrat const &bureaucrat);
};

#endif