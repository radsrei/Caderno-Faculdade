-- Este é um comentário de apenas uma linha

{- Este é um comentário de várias linhas
   Bloco de comentário com várias linhas
-}

{- É possível agrupar múltiplas linhas -}

-- Aqui foi definido uma variável ''greeting'' do tipo String
greeting =
    "Hello World!"

 -- É melhor adicionar o tipo das anotações nas declarações ao topo
hello : String
hello =
    "Hi there."

-- Funções são declaradas da mesma forma e os argumentos seguem o nome padrão da função
add x y =
    x + y

-- Novamente o ideal é adicionar o tipo das anotações
hypotenuse : Float -> Float -> Float
hypotenuse a b =
    sqrt (a^2 + b^2)

-- Funções também manipulam vários argumentos de uma vez, aqui um caso da função de multiplicação
-- Operador infico com "2"
multiplyBy2 : number -> number
multiplyBy2 =
    (*) 2

-- Expressões if são usadas para desviar valores
absoluteValue : number -> number
absoluteValue number =
    if number < 0 then negate number else number

 -- Registros são usados para manter valores com campos nomeados
book : { title : String, author : String, pages : Int }
book =
    { title = "Steppenwolf"
    , author = "Hesse"
    , pages = 237 
    }

-- Acesso de registro é feito com "."
title : String
title =
    book.title

-- Acesso de registro "." também pode ser usado como uma função
author : String
author =
    .author book

-- Podemos criar tipos novos com a palavra-chave "type"
-- O valor a seguir representa uma árvore binária
type Tree a
    = Empty
    | Node a (Tree a) (Tree a)

-- É possível inpecionar esses tipos com expressões "case"
depth : Tree a -> Int
depth tree =
    case tree of
        Empty ->
            0

        Node value left right ->
            1 + max (depth left) (depth right)