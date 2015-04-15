import Control.Applicative
import Control.Monad
import Data.Maybe
import Data.Char
import Debug.Trace
import Data.Int (Int64)
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

getInts :: IO [Int]
getInts = map readInt . C.words <$> C.getLine

getInt :: IO Int
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

main :: IO ()
main = do
  (n:k:_) <- getInts
  str' <- getLine
  let str = map digitToInt str'
      s = sum str
      arr = zip str [0..]
