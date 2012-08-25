setClass("SuffixTree", representation(type="character", tree="externalptr"), prototype(type=NULL, tree=NULL))

setMethod("initialize", "SuffixTree", function(.Object, src) {
	.type <- switch(class(src), character = "character", integer = "integer")
	if (is.null(.type)) {
		stop("Invalid src type")
	}
	.Object@type <- .type
	.Object@tree <- .Call(paste("Rlibstree__new__", .type, sep=""), src)
	return(.Object)
})

setMethod( "$", "SuffixTree", function(x, name) {
	function(...) .Call(paste("Rlibstree", name, sep="__"), x@tree, ...)			
})

setMethod("print",
		signature(x = "SuffixTree"),
		function (x, ...) 
		{
			.Call("Rlibstree__print", x@tree)
		}
)
