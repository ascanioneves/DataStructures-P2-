inverte :: [a] -> [a]
inverte [] = [] --caso a lista esteja vazia, eu retorno uma lista vazia
inverte (x:xs) = (inverte xs) ++ [x]