library(Rlibstree)

temp1 <- new("SuffixTree", "banana")
temp2 <- new("SuffixTree", c(2L, 1L, 3L, 1L, 3L, 1L));
tryCatch({
		new("SuffixTree", 1:3)
		stop("Error!!")
	}, error = function(e) { })
