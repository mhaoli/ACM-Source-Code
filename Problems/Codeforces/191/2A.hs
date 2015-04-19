import Control.Applicative
import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

getInts :: IO [Int]
getInts = map readInt . C.words <$> C.getLine

getInt :: IO Int
getInt = readInt <$> C.getLine

gao :: [Int] -> Int
gao [] = 0
gao [x] = max 0 x
gao all@(x:xs) = max solve $ gao xs
  where
  solve = maximum $ scanl (+) 0 all

main :: IO ()
main = do
  _ <- getInt
  a <- getInts
  let cnt = sum a
      a' = map (\x -> if x==1 then -1 else 1) a
  print (if cnt == (length a) then cnt - 1 else cnt + (gao a'))
