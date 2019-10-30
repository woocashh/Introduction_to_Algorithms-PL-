
module GADTS where

data Expr
    = EInt Int
    | EAdd Expr Expr
    | EMul Expr Expr
    | ESub Expr Expr
    | EBool Bool
    | EEq Expr Expr
    | EIf Expr Expr Expr
    deriving Show


 -- Do notation    

eval :: Expr -> Maybe Int
eval (EInt i) = Just i
eval (EAdd i1 i2) = do
    i1' <- eval i1
    i2' <- eval i2
    return (i1' + i2')

eval (EMul i1 i2) = do
    i1' <- eval i1
    i2' <- eval i2
    return (i1' * i2')

eval (ESub i1 i2) = do
    i1' <- eval i1
    i2' <- eval i2
    return (i1' - i2')


eval (EIf b t f)
  = if evalBool b then eval t else eval f

evalBool :: Expr -> Bool
evalBool (EBool b) = b
evalBool (EEq e1 e2) = eval e1 == eval e2



instance Num Expr where
    (+) = EAdd
    (*) = EMul
    (-) = ESub
    fromInteger = EInt . fromInteger
    abs = error "NO"
    signum = error "NO"



-- Case syntax
foobar :: Bool -> String
foobar b = case b of
    True -> "foo"
    False -> "bar"