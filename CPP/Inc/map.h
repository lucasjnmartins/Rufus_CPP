/*
 * map.h
 *
 *  Created on: Jun 26, 2022
 *      Author: Lucas Martins
 */

#ifndef MAP_H_
#define MAP_H_

#include "main.h"

class map {
public:
	map();
	virtual ~map();

private:
	int baseSpeed[TRACKS];
	float kp[TRACKS];
	float ki[TRACKS];

};

#endif /* MAP_H_ */
