/*
 * Tree.h
 *
 *  Created on: Aug 25, 2012
 *      Author: wush
 */

#ifndef TREE_H_
#define TREE_H_

#include "libstree.h"

namespace Rlibstree {

class Tree {
	LST_String* src;
	LST_StringSet* set;
	LST_STree* tree;

public:
	Tree(void *data, u_int item_size, u_int num_items);
	virtual ~Tree();

private:
	Tree(const Tree&);
	void operator=(const Tree&);
};

} /* namespace Rlibstree */
#endif /* TREE_H_ */
