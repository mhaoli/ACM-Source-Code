import Control.Applicative
import Control.Monad
import Data.Maybe
import Debug.Trace
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

getInts :: IO [Int]
getInts = map readInt . C.words <$> C.getLine

getInt :: IO Int
getInt = readInt <$> C.getLine

main :: IO ()
main = do
  [x,y] <- getInts
  putStrLn $ unwords $ map show $ calc x y
  where
    calc x y
      | x > 0 && y > 0 = [0,t,t,0]
      | x > 0 && y < 0 = [0,-t,t,0]
      | x < 0 && y > 0 = [-t,0,0,t]
      | otherwise = [-t,0,0,-t]
      where 
        t = (abs x) + (abs y)
