local lisp = require "newLISP"

local result = lisp.eval("(+ 1 2)")
print(result)
print("-----------------------------------------")

result = lisp.eval2("(define (mk x y) (+ (* x x) (* y y))) (mk 3 4)")
print(result)
print("-----------------------------------------")

result = lisp.eval_file("t.lsp")
print(result)

print("-----------------------------------------")

print("Done")
