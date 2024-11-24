#ifndef HARL_HPP
#define ARL_HPP

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		void complain(const std::string level);
};