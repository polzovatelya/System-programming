namespace Laba7SP
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(585, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(203, 62);
            this.button1.TabIndex = 0;
            this.button1.Text = "Эмблема";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            this.button1.Paint += new System.Windows.Forms.PaintEventHandler(this.button1_Paint);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(585, 80);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(203, 62);
            this.button2.TabIndex = 1;
            this.button2.Text = "Флаг";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            this.button2.Paint += new System.Windows.Forms.PaintEventHandler(this.button2_Paint);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(585, 148);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(203, 62);
            this.button3.TabIndex = 2;
            this.button3.Text = "Текстура";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            this.button3.Paint += new System.Windows.Forms.PaintEventHandler(this.button3_Paint);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(585, 216);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(203, 62);
            this.button4.TabIndex = 3;
            this.button4.Text = "Фигуры";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            this.button4.Paint += new System.Windows.Forms.PaintEventHandler(this.button4_Paint);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(585, 284);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(203, 62);
            this.button5.TabIndex = 4;
            this.button5.Text = "Случайное движение";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            this.button5.Paint += new System.Windows.Forms.PaintEventHandler(this.button5_Paint);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(585, 352);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(203, 62);
            this.button6.TabIndex = 5;
            this.button6.Text = "Угловое движение";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            this.button6.Paint += new System.Windows.Forms.PaintEventHandler(this.button6_Paint);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(376, 352);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(203, 62);
            this.button7.TabIndex = 6;
            this.button7.Text = "Среднее движение";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            this.button7.Paint += new System.Windows.Forms.PaintEventHandler(this.button7_Paint);
            // 
            // button8
            // 
            this.button8.Location = new System.Drawing.Point(376, 284);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(203, 62);
            this.button8.TabIndex = 7;
            this.button8.Text = "Экран";
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.button8_Click);
            this.button8.Paint += new System.Windows.Forms.PaintEventHandler(this.button8_Paint);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
    }
}

