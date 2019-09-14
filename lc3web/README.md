# lc3web
web-based simulator for LC-3

This is based off of wchargin's LC-3 web [simulator]. I (yihchun) have
updated it so that the interrupts work better. In particular, wchargin's
original simulator uses the User Stack Pointer for supervisor mode
execution; I've made it swap in the appropriate stack pointer based on
the current mode of execution. The main advantage of this is not needing
to set R6 in interrupt demonstration code. I've also removed the Google
Analytics tracking code.

If you're using this code, be aware that DSR becomes ready very quickly,
so your user code may never execute when the DSR enable-interrupts is set.

[simulator]: https://github.com/wchargin/lc3web
