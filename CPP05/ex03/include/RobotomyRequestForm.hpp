#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // rand()
#include <ctime> // srand() без выдает фикс число

class RobotomyRequestForm : public AForm {
	private:
		const std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(RobotomyRequestForm const &assign);
		~RobotomyRequestForm();

		virtual void execute(const Bureaucrat& executor) const;
};

#endif
