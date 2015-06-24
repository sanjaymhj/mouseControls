using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace mousecoordinate
{
    public partial class Form1 : Form
    {
        [DllImport("mouseControls.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static bool move_cursorTo(int x, int y);
        
        [DllImport("mouseControls.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static bool click_Left_down(int x, int y);

        [DllImport("mouseControls.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static bool click_Right_up(int x, int y);

        [DllImport("mouseControls.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static bool click_Left_up(int x, int y);

        [DllImport("mouseControls.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static bool click_Right_down(int x, int y);


        public Form1()
        {
            InitializeComponent();

            Thread t = new Thread(new ThreadStart(ThreadProc));

            // Start ThreadProc.  Note that on a uniprocessor, the new  
            // thread does not get any processor time until the main thread  
            // is preempted or yields.  Uncomment the Thread.Sleep that  
            // follows t.Start() to see the difference.
            t.Start();
            //Thread.Sleep(0); 

            
           
        }

        private void ThreadProc()
        {
            bool a;
            //int i = 0;
            for (int i = 0; i < 10; i++)
            {
                a = move_cursorTo(i * 3, i * 2);
                Thread.Sleep(1000);
            }
            a = move_cursorTo(200, 20);
            bool b=click_Left_down(200,20);
            a = move_cursorTo(500, 500);
            bool l_click_Up = click_Left_up(200, 20);
            //Thread.Sleep(1000);

            //bool c=click_Left_down(200, 20);
            //c = click_Left_down(200, 20);

            //            Thread.Sleep(1000);
            bool r_click_d = click_Right_down(200, 20);
            bool d=click_Right_up(100, 20);
            Thread.Sleep(1000);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Thread t = new Thread(new ThreadStart(ThreadProc));
            t.Start();

        }

      
    }
}
