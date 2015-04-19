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

main :: IO ()
main = do
  n <- getInt
  putStrLn $ unwords $ map show $ take n [n..]
