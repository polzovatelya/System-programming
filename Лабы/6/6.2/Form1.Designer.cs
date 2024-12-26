namespace _6._2
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
            this.Flag = new System.Windows.Forms.Button();
            this.Figure = new System.Windows.Forms.Button();
            this.Moving = new System.Windows.Forms.Button();
            this.Rotation_left = new System.Windows.Forms.Button();
            this.Rotation_point = new System.Windows.Forms.Button();
            this.Back = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // Flag
            // 
            this.Flag.BackColor = System.Drawing.Color.Honeydew;
            this.Flag.Location = new System.Drawing.Point(12, 461);
            this.Flag.Name = "Flag";
            this.Flag.Size = new System.Drawing.Size(95, 73);
            this.Flag.TabIndex = 0;
            this.Flag.Text = "Флаг";
            this.Flag.UseVisualStyleBackColor = false;
            this.Flag.Click += new System.EventHandler(this.Flag_Click);
            this.Flag.Paint += new System.Windows.Forms.PaintEventHandler(this.Flag_Paint);
            // 
            // Figure
            // 
            this.Figure.Location = new System.Drawing.Point(139, 461);
            this.Figure.Name = "Figure";
            this.Figure.Size = new System.Drawing.Size(102, 73);
            this.Figure.TabIndex = 1;
            this.Figure.Text = "Фигуры";
            this.Figure.UseVisualStyleBackColor = true;
            this.Figure.Click += new System.EventHandler(this.Figure_Click);
            this.Figure.Paint += new System.Windows.Forms.PaintEventHandler(this.Flag_Paint);
            // 
            // Moving
            // 
            this.Moving.Location = new System.Drawing.Point(247, 461);
            this.Moving.Name = "Moving";
            this.Moving.Size = new System.Drawing.Size(118, 73);
            this.Moving.TabIndex = 2;
            this.Moving.Text = "Перемещение";
            this.Moving.UseVisualStyleBackColor = true;
            this.Moving.Click += new System.EventHandler(this.Moving_Click);
            this.Moving.Paint += new System.Windows.Forms.PaintEventHandler(this.Flag_Paint);
            // 
            // Rotation_left
            // 
            this.Rotation_left.Location = new System.Drawing.Point(371, 461);
            this.Rotation_left.Name = "Rotation_left";
            this.Rotation_left.Size = new System.Drawing.Size(121, 73);
            this.Rotation_left.TabIndex = 3;
            this.Rotation_left.Text = "Вращение 1";
            this.Rotation_left.UseVisualStyleBackColor = true;
            this.Rotation_left.Click += new System.EventHandler(this.Rotation_left_Click);
            this.Rotation_left.Paint += new System.Windows.Forms.PaintEventHandler(this.Flag_Paint);
            // 
            // Rotation_point
            // 
            this.Rotation_point.Location = new System.Drawing.Point(498, 461);
            this.Rotation_point.Name = "Rotation_point";
            this.Rotation_point.Size = new System.Drawing.Size(122, 73);
            this.Rotation_point.TabIndex = 4;
            this.Rotation_point.Text = "Вращение 2";
            this.Rotation_point.UseVisualStyleBackColor = true;
            this.Rotation_point.Click += new System.EventHandler(this.Rotation_point_Click);
            this.Rotation_point.Paint += new System.Windows.Forms.PaintEventHandler(this.Flag_Paint);
            // 
            // Back
            // 
            this.Back.Location = new System.Drawing.Point(626, 461);
            this.Back.Name = "Back";
            this.Back.Size = new System.Drawing.Size(100, 73);
            this.Back.TabIndex = 5;
            this.Back.Text = "Фон";
            this.Back.UseVisualStyleBackColor = true;
            this.Back.Click += new System.EventHandler(this.Back_Click);
            this.Back.Paint += new System.Windows.Forms.PaintEventHandler(this.Flag_Paint);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // timer2
            // 
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(1063, 553);
            this.Controls.Add(this.Back);
            this.Controls.Add(this.Rotation_point);
            this.Controls.Add(this.Rotation_left);
            this.Controls.Add(this.Moving);
            this.Controls.Add(this.Figure);
            this.Controls.Add(this.Flag);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Flag;
        private System.Windows.Forms.Button Figure;
        private System.Windows.Forms.Button Moving;
        private System.Windows.Forms.Button Rotation_left;
        private System.Windows.Forms.Button Rotation_point;
        private System.Windows.Forms.Button Back;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Timer timer2;
    }
}

