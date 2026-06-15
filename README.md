# kernel-driver
<img width="948" height="593" alt="dd8c908ed08c431031fde66aaece33ac" src="https://github.com/user-attachments/assets/9ff6c4d3-62ce-47b8-961d-b26fc2119b04" />

## reference
https://tldp.org/LDP/lkmpg/2.6/html/index.html
##
What exactly is a kernel module? Modules are pieces of code that can be loaded and unloaded into the kernel upon demand. They extend the functionality of the kernel without the need to reboot the system. For example, one type of module is the device driver, which allows the kernel to access hardware connected to the system. Without modules, we would have to build monolithic kernels and add new functionality directly into the kernel image. Besides having larger kernels, this has the disadvantage of requiring us to rebuild and reboot the kernel every time we want new functionality.
<br>
<img width="1280" height="591" alt="kernel mode" src="https://github.com/user-attachments/assets/828c506c-84f7-4597-b73c-565041285bab" />

##
You can see what modules are already loaded into the kernel by running lsmod, which gets its information by reading the file /proc/modules.
<br>
<img width="629" height="335" alt="lsmod" src="https://github.com/user-attachments/assets/c29c3c2c-cf4a-4439-aed4-63382c10e75a" />
##
Kernel modules must have at least two functions: a "start" (initialization) function called init_module() which is called when the module is insmoded into the kernel, and an "end" (cleanup) function called cleanup_module() which is called just before it is rmmoded.
<br><br>
Typically, init_module() either registers a handler for something with the kernel, or it replaces one of the kernel functions with its own code (usually code to do something and then call the original function). The cleanup_module() function is supposed to undo whatever init_module() did, so the module can be unloaded safely.
<br><br>
As of Linux 2.4, you can rename the init and cleanup functions of your modules; they no longer have to be called init_module() and cleanup_module() respectively. This is done with the module_init() and module_exit() macros. These macros are defined in linux/init.h. The only caveat is that your init and cleanup functions must be defined before calling the macros, otherwise you'll get compilation errors.
##
<code>printk()</code> is alogging mechanism for the kernel, and is used to log information or give warnings. Therefore, each printk() statement comes with a priority. There are 8 priorities and the kernel has macros for them. If you don't specify a priority level, the default priority, DEFAULT_MESSAGE_LOGLEVEL, will be used.

<img width="723" height="415" alt="syslog" src="https://github.com/user-attachments/assets/cf507fc0-3efc-4c67-8c0e-548823f18de7" />
<br><br>
<img width="433" height="144" alt="kern levels" src="https://github.com/user-attachments/assets/b3aa0056-e00c-4b2a-88e6-ab276e6a0291" />
<br>
## 
<br>
Compile with Makefile settings <br>
<code>make</code> <br>
This generates .ko : the kernel module.<br>
Load: <code>sudo insmod (module).ko</code><br>
Unload: <code>sudo rmmod (module)</code><br>
Check the log: <code>dmesg</code><br>
##
<br> Congratulations, you are now the author of Linux kernel code!
