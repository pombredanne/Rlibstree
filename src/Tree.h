/*
 * Tree.h
 *
 *  Created on: Aug 25, 2012
 *      Author: wush
 */

#ifndef TREE_H_
#define TREE_H_

#include <ostream>
#include <vector>
#include "libstree.h"

namespace Rlibstree {

struct Interval{
	u_int start;
	u_int end;
};

class Tree {
	bool is_character;
	LST_String* src;
	LST_StringSet* set;
	LST_STree* tree;
	u_int size;
	std::vector<LST_Node*> leaf_index;

public:
	Tree(void *data, const u_int item_size, const u_int num_items);
	virtual ~Tree();

	void print();

	/**
	 * @u_int location   start from 0
	 * @u_int length of LSUS
	 */
	const u_int getLSUS(const u_int location);

	/**
	 * @u_int location   start from 0
	 * @u_int& start	return: start location(start from 0)
	 * @u_int& end	    return: end location(start from 0)
	 */
	void getSUSBaseline(const u_int location, u_int& start, u_int& end);

private:
	Tree(const Tree&);
	void operator=(const Tree&);
};

} /* namespace Rlibstree */
#endif /* TREE_H_ */
