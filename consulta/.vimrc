" enable line number and set 4-space indents w/ soft tabs
set nocompatible
set nu
set ts=4 sw=4 sts=4 et

" Stroustrup/Java/Linux format
set formatoptions+=tcqlron
" more info? :h cinoptions-values
set cinoptions=:0,l1,t0,g0

" indent sensibly and eat soft tabs like expected
set smarttab autoindent smartindent
set backspace=start,indent,eol

" match angle brackets (templates/includes/generics)
set matchpairs+=<:>

" hide mouse while typing
set mousehide
if has("mouse")
    set mouse=a
endif

set nobackup nowritebackup noswapfile
