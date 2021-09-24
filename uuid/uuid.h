#pragma once
#ifndef UUID_H
#define UUID_H
#include <string>
#include <random>

namespace stde
{
	class uuid
	{
		static const char chars[];
		static std::random_device engine;
	public:
		static std::string get_uuid()
		{
			std::string uuid;
			uuid.resize(36);

			std::mt19937 rnd(engine());
			std::uniform_int_distribution distr(0, 16);
			uuid[8] = uuid[13] = uuid[18] = uuid[23] = '-';
			uuid[14] = '4'; // version 4

			for (int i = 0, r = 0; i < 36; ++i)
			{
				if (!uuid[i])
				{
					r = distr(rnd);
					uuid[i] = chars[(i == 19) ? (r & 0x3) | 0x8 : r & 0xf];
				}
			}

			return uuid;
		}
	};
	const char uuid::chars[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	std::random_device uuid::engine;
}
#endif