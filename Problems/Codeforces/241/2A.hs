import Control.Applicative
import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

transform :: String -> String -> Int -> (Ordering, Int)
transform "Y" ">=" x = (GT, x-1)
transform "N" ">=" x = (LT, x)
transform "Y" "<=" x = (LT, x+1)
transform "N" "<=" x = (GT, x)
transform "Y" ">" x = (GT, x)
transform "N" ">" x = (LT, x+1)
transform "Y" "<" x = (LT, x)
transform "N" "<" x = (GT, x-1)
transform _ _ _ = undefined

main :: IO ()
main = do 
  n <- readInt <$> C.getLine
  array <- replicateM n $ do
    [symbol, x, ans] <- C.words <$> C.getLine
    return $ transform (C.unpack ans) (C.unpack symbol) (readInt x)
  let lt = [y | (x,y) <- array, x == LT]
      gt = [y | (x,y) <- array, x == GT]
      ltmi = minimum lt
      gtmx = maximum gt
  if null lt then print $ gtmx + 1
  else if null gt then print $ ltmi - 1
  else if ltmi - 1 > gtmx then print $ ltmi - 1
  else putStrLn "Impossible"
