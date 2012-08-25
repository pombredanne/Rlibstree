/*
 * Rlibstree.Rfunction.cpp
 *
 *  Created on: Aug 25, 2012
 *      Author: wush
 */

#include "Rlibstree.h"

using namespace Rcpp;

SEXP Rlibstree__new__string(SEXP Rsrc) {

	BEGIN_RCPP
	XPtr<Rlibstree::Tree> tree(new Rlibstree::Tree((void*) CHAR(STRING_ELT(Rsrc,0)), 1, Rf_length(STRING_ELT(Rsrc, 0))));
	return tree;
	END_RCPP

}

SEXP Rlibstree__new__int(SEXP Rsrc) {
	return R_NilValue;
}




