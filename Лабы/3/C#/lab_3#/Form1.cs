using System.Windows.Forms;

namespace lab_3_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            button1.Click += button1_Click;
            colorDialog1.FullOpen = true;
            // установка начального цвета для colorDialog
            colorDialog1.Color = this.BackColor;
        }
        void button1_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.Cancel)
                return;
            // установка цвета формы
            this.BackColor = colorDialog1.Color;
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}