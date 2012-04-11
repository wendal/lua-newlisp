Lua-newLISP包装器
=============================================

*在lua中调用newLISP脚本. 项目创建的主要目的是在lua_nginx模块中,使用newLISP脚本.

编译
---------------------------------------------

  * libnewlisp.so拷贝到/usr/lib
  * 将newLISP.so访问lua的cpath


API
---------------------------------------------

  * eval(str)
    
    * 执行并返回最后一个表达式的值,返回值的类型是str


  * eval_file(file_path)

    * 执行一个文件,并返回最后一个表达式的值,返回值的类型是str


示例

<pre>
  -- 载入newLISP库
  local lisp = require "newLISP"

  -- 执行一个简单的newLISP脚本字符串
  local result = lisp.eval("(+ 1 2)")
  print(result)
  print("-----------------------------------------")

  -- 执行一个带方法定义的newLISP脚本字符串
  result = lisp.eval2("(define (mk x y) (+ (* x x) (* y y))) (mk 3 4)")
  print(result)
  print("-----------------------------------------")

  -- 执行一个lsp文件
  result = lisp.eval_file("t.lsp")
  print(result)

  print("-----------------------------------------")
</pre>
  