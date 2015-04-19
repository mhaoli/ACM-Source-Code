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
