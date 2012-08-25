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

#endif /* RLIBSTREE_H_ */
