import Control.Applicative
import Control.Monad
import Data.Int (Int64)
import Data.Maybe
import Debug.Trace
import qualified Data.ByteString.Char8 as C

readInt :: Integral a => C.ByteString -> a
readInt = fromIntegral . fst . fromJust . C.readInt

getInts :: IO [Int64]
getInts = map readInt . C.words <$> C.getLine

getInt :: IO Int64
getInt = readInt <$> C.getLine

gao :: Int64 -> [(Int64, Int64)] -> Int64 -> Int -> Int
gao s [] n res = res + if s < n then 1 else 0
gao _ [_] _ res = res + 1
gao s all@((i,x) : (j,y) : xs) n res 
  | s > i = gao i all n res
  | m /= 0 || l <= 0 = gao j ((j,y) : xs) n $ res + 1
  | otherwise = gao next xs' n $ res + 1
  where
  (d,m) = (y - x) `quotRem` (j - i)
  l = x - (i - s) * d
  next = if d >= 0 then n else j + (y-1) `quot` (-d) + 1
  xs' = dropWhile (\(k,z) -> z == (k-j)*d + y) xs

main :: IO ()
main = do
  n <- getInt
  array <- getInts
  print $ gao 0 [k | k@(_,i) <- zip [0..] array, i > 0] n 0
