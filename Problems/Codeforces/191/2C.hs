import Control.Applicative
import Control.Monad
import Data.Char
import Data.Maybe
import Data.Int (Int64)
import Debug.Trace
import qualified Data.ByteString.Char8 as C

readInt :: Integral a => C.ByteString -> a
readInt = fromIntegral . fst . fromJust . C.readInt

getInts :: IO [Int64]
getInts = map readInt . C.words <$> C.getLine

getInt :: IO Int64
getInt = readInt <$> C.getLine

newtype Mint = Mint Int64

mymod :: Int64
mymod = 1000000007

instance Show Mint where
  show (Mint a) = show a

instance Num Mint where
  (+) (Mint a) (Mint b) = Mint $ let c = a + b in if c >= mymod then c - mymod else c
  (-) (Mint a) (Mint b) = Mint $ let c = a - b in if c < 0 then c + mymod else c
  (*) (Mint a) (Mint b) = Mint $ a * b `rem` mymod
  abs                   = id
  signum (Mint a)       = Mint $ signum a
  fromInteger a         = Mint $ fromInteger $ a `mod` toInteger mymod

myDiv :: Mint -> Mint -> Mint
myDiv (Mint a) (Mint b) = Mint $ (if odd a then (a-1) else a) `div` b

powMod :: Mint -> Mint -> Mint
powMod _ (Mint 0) = Mint 1
powMod p n@(Mint t)
  | odd t = p * tmp
  | otherwise = tmp
  where
  tmp = powMod (p * p) (n `myDiv` (Mint 2))

main :: IO ()
main = do
  n <- getLine
  k <- getInt
  let len = fromIntegral $ length n
      n' = [(Mint i) | (i,x) <- zip [0..] n, x == '5' || x == '0']
      d = powMod (Mint 2) $ Mint len
      x = (powMod d (Mint k)) - (Mint 1)
      x' = x * (powMod (d-(Mint 1)) $ Mint $ mymod - 2)
  print $ x' * foldl (\t x -> t + (powMod (Mint 2) x)) (Mint 0) n'
