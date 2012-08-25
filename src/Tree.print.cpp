/*
 * Tree.print.cpp
 *
 *  Created on: Aug 25, 2012
 *      Author: wush
 */

#include "Tree.h"
#include <R.h>
#include <string>
#include <sstream>

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
		std::string output_string(edge->range.string->sclass->print_func(&edge->range));
		if (output_string.compare("<eos>")) {
			uint
				start = edge->range.start_index,
				end = *(edge->range.end_index);
			int* int_array = reinterpret_cast<int*>(edge->range.string->data);
			std::stringstream ss;
			for (int i = start; i <= end && int_array[i] != 0; i++) {
				if (i != start) {
					ss << ",";
				}
				ss << int_array[i];
			}
			output_string = ss.str();
		}
		if (edge->dst_node->kids.lh_first) {
			Rprintf("\t'%s' %u\n",
				output_string.c_str(),
				edge->dst_node->id);
		}
		else {
			Rprintf("\t'%s' [%i] %u%c%c\n",
				output_string.c_str(),
				edge->dst_node->index,
				edge->dst_node->id,
				(edge->range.end_index == &edge->range.end_index_local) ? 'l' : 't',
				(edge->range.end_index == tree->phase) ? 'c' : ' ');
		}
	}
	return 1;
}

void Tree::print() {

	if (is_character)
		lst_alg_dfs(tree, &print_node_character, tree);
	else
		lst_alg_dfs(tree, &print_node_integer, tree);

}

}

