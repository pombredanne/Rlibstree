/*
 * Rlibstree.Rfunction.cpp
 *
 *  Created on: Aug 25, 2012
 *      Author: wush
 */

#include "Rlibstree.h"

using namespace Rcpp;

SEXP Rlibstree__new__character(SEXP Rsrc) {

	BEGIN_RCPP
	XPtr<Rlibstree::Tree> tree(new Rlibstree::Tree((void*) CHAR(STRING_ELT(Rsrc,0)), 1, Rf_length(STRING_ELT(Rsrc, 0))));
	return tree;
	END_RCPP

}

SEXP Rlibstree__new__integer(SEXP Rsrc) {

	BEGIN_RCPP
	XPtr<Rlibstree::Tree> tree(new Rlibstree::Tree( (void*) INTEGER(Rsrc), sizeof(int), Rf_length(Rsrc) ));
	return tree;
	END_RCPP
}

SEXP Rlibstree__print(SEXP Rtree) {

	BEGIN_RCPP

	XPtr<Rlibstree::Tree> tree(Rtree);
	tree->print();

	END_RCPP

}

SEXP Rlibstree__getLSUS(SEXP Rtree, SEXP Rlocation) {

	BEGIN_RCPP

	XPtr<Rlibstree::Tree> tree(Rtree);
	IntegerVector location(Rlocation);
	IntegerVector retval(location.size());
	for(int i = 0;i < location.size();i++) {
		retval[i] = tree->getLSUS(location[i] - 1);
	}
	return retval;

	END_RCPP

}

SEXP Rlibstree__getSUSBaseline(SEXP Rtree, SEXP Rlocation) {

	BEGIN_RCPP

	XPtr<Rlibstree::Tree> tree(Rtree);
	IntegerVector location(Rlocation);
	IntegerVector retval_start(location.size()), retval_end(location.size());
//	u_int start, end;
	for(int i = 0;i < location.size();i++) {
//		tree->getSUSBaseline(location[i] - 1, start, end);
//		retval_start[i] = start;
//		retval_end[i] = end;
		tree->getSUSBaseline(location[i] - 1, (u_int&) retval_start[i], (u_int&) retval_end[i]);
		retval_start[i]++;
		retval_end[i]++;
	}
	List retval;
	retval["start"] = retval_start;
	retval["end"] = retval_end;
	return retval;

	END_RCPP

}

SEXP Rlibstree__getSUSProposed(SEXP Rtree, SEXP Rlocation) {

	BEGIN_RCPP

	XPtr<Rlibstree::Tree> tree(Rtree);
	IntegerVector location(Rlocation);
	IntegerVector retval(location.size());
	for(int i = 0;i < location.size();i++) {
//	TODO	retval[i] = tree->getLSUS(location[i] - 1);
	}
	return retval;

	END_RCPP


}

