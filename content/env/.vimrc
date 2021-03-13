" set nu ts=4 sw=4 ai st cin tm=50 noeb cul ru

set number

set tabstop=4
set shiftwidth=4
set autoindent
set smarttab
set cindent

set timeoutlen=50

set cursorline

" to run executable
set exrc

set autowrite
set autoread

set nowrap

" compile & run

map <F5> :<C-U>!g++ -O2 -DLOCAL -std=c++11 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address %:r.cpp -o %:r<CR>
map <F9> :<C-U>!./%:r<CR>
