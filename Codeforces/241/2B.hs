import Control.Applicative
import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

getInts :: IO [Int]
getInts = map readInt . C.words <$> C.getLine

gao :: [Int] -> [Int] -> [Int]
gao a b = let c = zipWith (+) b $ zipWith max a (0:c) in c

main :: IO ()
main = do
  [m,n] <- getInts
  arr <- replicateM m getInts
  let ans = tail . map last $ scanl gao (replicate n 0) arr
  putStrLn $ unwords $ map show ans
