qsort [] = []
qsort (x:xs) = qsort esq_x ++ [x] ++ qsort dir_x -- chamada pra esquerda e pra direita
            where
                esq_x = [y | y <- xs, y < x] -- menores que o pivot ficam a esquerda
                dir_x = [y | y <- xs, y >= x] -- maiores/iguais ficam a direita