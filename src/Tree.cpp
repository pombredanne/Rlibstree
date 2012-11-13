/*
 * Tree.cpp
 *
 *  Created on: Aug 25, 2012
 *      Author: wush
 */

#include "Tree.h"
#include <vector>
#include <memory>
#include <algorithm>
#ifdef DEBUG
#include <stdexcept>
#include <R.h>
#endif

namespace Rlibstree {

struct RecordLeafData {
	u_int index;
	std::vector<LST_Node*> *node_index;
};

int recordLeaf(LST_Node *node, void *data) {
	RecordLeafData* param = reinterpret_cast<RecordLeafData*>(data);
	param->node_index->push_back(node);
	param->index -= 1;
#ifdef DEBUG
	Rprintf("index: %d\n", param->index);
#endif
	if (!param->index) {
		return 0;
	}
	return 1;
}

inline const bool isEOF(LST_StringIndex index) {
	return index.start_index == index.string->num_items - 1;
}

Tree::Tree(void *data, const u_int item_size, const u_int num_items)
: is_character(item_size == 1), src(lst_string_new(data, item_size, num_items)), set(lst_stringset_new()), tree(NULL), size(num_items)
{
	lst_stringset_add(set, src);
	tree = lst_stree_new(set);
	std::auto_ptr<RecordLeafData> param_ptr(new RecordLeafData);
	param_ptr->node_index = &leaf_index;
	param_ptr->index = size + 1;
	lst_alg_leafs(tree, recordLeaf, (void*) param_ptr.get());
	std::reverse(leaf_index.begin(), leaf_index.end());
#ifdef DEBUG
	if (leaf_index.size() != size) {
		Rprintf("%d\n", leaf_index.size());
		throw std::logic_error("leaf index length incorrect");
	}
#endif
}

Tree::~Tree() {
	lst_stree_free(tree);
}

const u_int Tree::getLSUS(const u_int location) {
	LST_Node* node = leaf_index[location];
	LST_StringIndex index = node->up_edge->range;
	if (isEOF(index)) {
		return size;
	}
	else {
		u_int L = *(index.end_index) - index.start_index;
		L = size - location + 1 - L;
		return L;
	}
}

void Tree::getSUSBaseline(const u_int location, u_int& start, u_int& end) {
	u_int LSUS_length = getLSUS(location);
	if (LSUS_length == size) {
		start = 0;
		end = size - 1;
	}
	else {
		start = location;
		end = location + LSUS_length - 1;
	}
	u_int temp_end;
	for( int k = location - 1; k >= 0 && location - k <= end - start; k--) {
		LSUS_length = getLSUS(k);
		if (LSUS_length == size) {
			continue;
		}
		temp_end = k + LSUS_length - 1;
		if (temp_end < location) {
			temp_end = location;
		}
		if (temp_end - k <= end - start) {
			start = k;
			end = temp_end;
		}
	}
}

} /* namespace Rlibstree */
