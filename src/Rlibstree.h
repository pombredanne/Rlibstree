/*
 * Rlibstree.h
 *
 *  Created on: Aug 25, 2012
 *      Author: wush
 */

#ifndef RLIBSTREE_H_
#define RLIBSTREE_H_

#include <memory>

#include <Rcpp.h>

#include "libstree.h"

#include "Tree.h"

RcppExport SEXP Rlibstree__new__character(SEXP Rsrc);
RcppExport SEXP Rlibstree__new__integer(SEXP Rsrc);

RcppExport SEXP Rlibstree__print(SEXP Rtree);

// Main Function

/**
 * @Rtree external_ptr of suffix tree
 * @Rlocation integer indicate query location, start from 1
 * @return 	length of LSUS
 */
RcppExport SEXP Rlibstree__getLSUS(SEXP Rtree, SEXP Rlocation);

RcppExport SEXP Rlibstree__getSUSBaseline(SEXP Rtree, SEXP Rlocation);

RcppExport SEXP Rlibstree__getSUSProposed(SEXP Rtree, SEXP Rlocation);

#endif /* RLIBSTREE_H_ */
