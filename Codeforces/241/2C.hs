--{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Control.Applicative
import Control.Monad
import Data.Maybe
import Data.Function (on)
import Data.List (sortBy)
import qualified Data.ByteString.Char8 as C
import qualified Data.Set as S

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

getInts :: IO [Int]
getInts = map readInt . C.words <$> C.getLine

getInt :: IO Int
getInt = readInt <$> C.getLine

gao :: S.Set(Int, Int) -> [((Int, Int), Int)] -> [((Int, Int), Int)]
gao _ [] = []
gao set (((c, p), i) : xs) = 
  case S.lookupGE (c, 0) set of
    Just k@(_, j) -> ((i, j), p) : gao (S.delete k set) xs
    Nothing -> gao set xs

main :: IO ()
main = do
  n <- getInt
  arr <- replicateM n $ do
    [c, p] <- getInts
    return (c, p)
  m <- getInt
  set <- S.fromList . flip zip [0..] <$> getInts
  let ans = gao set $ reverse . sortBy (compare `on` snd . fst) $ zip arr [0..]
  putStrLn $ unwords $ map show [length ans, sum $ map snd ans]
  putStr $ unlines . flip map ans $ \((i, j), _) -> show (i + 1) ++ " " ++ show (j + 1)
