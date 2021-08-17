#pragma once
#ifndef RANGE_H
#define RANGE_H
#include <type_traits>

namespace std
{
	template< typename NumberType = int, typename = typename std::enable_if<std::is_arithmetic<NumberType>::value, NumberType>::type  >
	class range {
	private:
		bool reversed;
		NumberType step;

		class range_iterator {
		private:
			bool reversed = false;
			NumberType step = 1;
		public:
			NumberType index = 0;
			range_iterator(NumberType x, bool reversed, NumberType step)
			{
				index = x;
				this->reversed = reversed;
				this->step = step;
			}

			void operator++()
			{
				if (reversed)
				{
					index -= step;
				}
				else
				{
					index += step;
				}
			}
			void operator--()
			{
				if (reversed)
				{
					index += step;
				}
				else
				{
					index -= step;
				}
			}

			const NumberType& operator*() const
			{
				return index;
			}

			bool operator==(const range_iterator& other) const
			{
				return index == other.index;
			}

			bool operator!=(const range_iterator& other) const
			{
				return index != other.index;
			}
		};
	public:
		NumberType range_begin = 0, range_end = 0;

		virtual range_iterator begin() const
		{
			if (!reversed)
				return range_iterator(range_begin < range_end ? range_begin : range_end, reversed, step);
			else
				return range_iterator(range_begin > range_end ? range_begin - 1 : range_end - 1, reversed, step);
		}
		virtual range_iterator end() const
		{
			if (!reversed)
				return range_iterator(range_begin < range_end ? range_end : range_begin, reversed, step);
			else
				return range_iterator(range_begin > range_end ? range_end - 1 : range_begin - 1, reversed, step);
		}
		virtual range_iterator rbegin() const
		{
			if (!reversed)
				return range_iterator(range_begin < range_end ? range_begin : range_end, reversed, step);
			else
				return range_iterator(range_begin > range_end ? range_begin - 1 : range_end - 1, reversed, step);
		}
		virtual range_iterator rend() const
		{
			if (!reversed)
				return range_iterator(range_begin < range_end ? range_end : range_begin, reversed, step);
			else
				return range_iterator(range_begin > range_end ? range_end - 1 : range_begin - 1, reversed, step);
		}
		range(NumberType start, NumberType end)
		{
			range_begin = start;
			range_end = end;
			reversed = false;
			step = 1;
		}
		range(NumberType start, NumberType end, bool reversed, NumberType step = 1)
		{
			range_begin = start;
			range_end = end;
			this->reversed = reversed;
			this->step = step;
		}
		range(NumberType end)
		{
			range_begin = 0;
			range_end = end;
			reversed = false;
			step = 1;
		}
	};
}
#endif