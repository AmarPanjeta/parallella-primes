/*
  Copyright (C) 2014 Adapteva, Inc.
  Contributed by Matt Thompson <mthompson@hexwave.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program, see the file COPYING.  If not, see
  <http://www.gnu.org/licenses/>.
*/

#include <math.h>

int is_prime(int coreid, long long int number)
{
	long long int i;
	long long int s = sqrt(number);
	if(number==2) return 1;
	//if(number&1==0) return 0;
	if(number%2==0) return 0;
	if(number==3) return 1;
	if(number%3==0) return 0;
	for(i=1+coreid;i<=s;i+=16)
	{
		if(number % (i*6+1) == 0 && number!=(i*6+1))
			return 0;
		if(number % (i*6-1) == 0 && number!=(i*6-1))
                        return 0;
	}
	return 1;
}
