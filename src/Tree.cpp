/*
 * Tree.cpp
 *
 *  Created on: Aug 25, 2012
 *      Author: wush
 */

#include "Tree.h"

namespace Rlibstree {

Tree::Tree(void *data, u_int item_size, u_int num_items)
: is_character(item_size == 1), src(lst_string_new(data, item_size, num_items)), set(lst_stringset_new()), tree(NULL)
{
	lst_stringset_add(set, src);
	tree = lst_stree_new(set);
}

Tree::~Tree() {
	lst_stree_free(tree);
}



} /* namespace Rlibstree */
