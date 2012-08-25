/*
 * Tree.print.cpp
 *
 *  Created on: Aug 25, 2012
 *      Author: wush
 */

#include "Tree.h"
#include <string>
#include <R.h>

namespace Rlibstree {


static int print_node_character(LST_Node *node, void *data) {
	if (!node->kids.lh_first) {
		return 1;
	}

	LST_STree *tree = reinterpret_cast<LST_STree*>(data);

	Rprintf("[%u (%u)", node->id, node->visitors);
	if (node->suffix_link_node) {
		Rprintf(" -> %u]\n", node->suffix_link_node->id);
	}
	else {
		Rprintf("]\n");
	}

	for(LST_Edge* edge = node->kids.lh_first;edge;edge = edge->siblings.le_next) {
		if (edge->dst_node->kids.lh_first) {
			Rprintf("\t'%s' %u (%s)\n",
				edge->range.string->sclass->print_func(&edge->range),
				edge->dst_node->id,
				lst_string_print(edge->range.string));
		}
		else {
			Rprintf("\t'%s' [%i] %u%c%c (%s)\n",
				edge->range.string->sclass->print_func(&edge->range),
				edge->dst_node->index,
				edge->dst_node->id,
				(edge->range.end_index == &edge->range.end_index_local) ? 'l' : 't',
				(edge->range.end_index == tree->phase) ? 'c' : ' ',
				lst_string_print(edge->range.string));
		}
	}
	return 1;
}

static int print_node_integer(LST_Node* node, void* data) {
	return 1;
}

void Tree::print() {

	if (is_character)
		lst_alg_dfs(tree, &print_node_character, this);
	else
		lst_alg_dfs(tree, &print_node_integer, this);

}

}

