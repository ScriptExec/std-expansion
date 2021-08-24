#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>

namespace std
{
	class input
	{
	public:
		input(const std::string& message = "")
		{
			_message = message;
		}

		~input()
		{
			_message.clear();
		}

		/*operator _type()
		{
			return get_input<_type>();
		}*/

		operator char()
		{
			return get_input<char>();
		}

		operator unsigned char()
		{
			return get_input<unsigned char>();
		}

		operator bool()
		{
			return get_input<bool>();
		}

		operator short()
		{
			return get_input<short>();
		}

		operator unsigned short()
		{
			return get_input<unsigned short>();
		}

		operator long()
		{
			return get_input<long>();
		}

		operator unsigned long()
		{
			return get_input<unsigned long>();
		}

		operator long long()
		{
			return get_input<long long>();
		}

		operator unsigned long long()
		{
			return get_input<unsigned long long>();
		}

		operator int()
		{
			return get_input<int>();
		}
		
		operator unsigned()
		{
			return get_input<unsigned>();
		}

		operator float()
		{
			return get_input<float>();
		}

		operator double()
		{
			return get_input<double>();
		}

		operator long double()
		{
			return get_input<long double>();
		}

		operator std::string()
		{
			return get_input<std::string>();
		}

	private:
		//_type _input;
		std::string _message;

	private:
		template<typename _type>
		_type get_input()
		{
			_type _input = _type();

			std::cout << _message;
			std::cin >> _input;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cin >> _input;
			}

			return _input;
		}
	};
}
#endif