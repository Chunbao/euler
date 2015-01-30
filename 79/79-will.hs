import Data.Graph as G
import Data.List

es :: [Int]
es = [319, 680, 180, 690, 129, 620, 762, 689, 762, 318, 368, 710, 720, 710, 629, 168, 160, 689, 716, 731, 736, 729, 316, 729, 729, 710, 769, 290, 719, 680, 318, 389, 162, 289, 162, 718, 729, 319, 790, 680, 890, 362, 319, 760, 316, 729, 380, 319, 728, 716]

digits :: Int -> [Int]
digits 0 = []
digits x = x `mod` 10 : digits (x `div` 10)

makeEdges :: [Int] -> [(Int, Int)]
makeEdges vs = zipWith (\x y -> (x,y)) vs (tail vs)

pairize :: [Int] -> [(Int, Int)]
pairize [] = []
pairize vs = nub $ foldr (\e a -> (makeEdges . digits) e ++ a) [] vs

bounds :: (Int, Int)
bounds = (0, 9)

uniqueDigits :: [Int]
uniqueDigits = nub . concat . map (\e -> digits e) $ es

answer = let ps = reverse . G.topSort $ (buildG bounds (pairize es)) in
             filter (\e -> e `elem` uniqueDigits) ps
main = putStrLn $ show answer
