using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.Win32;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            comboBox1.Items.AddRange(new string[] { "Красный", "Синий", "Фиолетовый",
                "Зелёный", "Жёлтый", "Оранжевый" });
            comboBox2.Items.AddRange(new string[] { "Красный", "Синий", "Фиолетовый",
                "Зелёный", "Жёлтый", "Оранжевый" });
            comboBox1.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            comboBox2.SelectedIndexChanged += comboBox2_SelectedIndexChanged;
            
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(comboBox1.SelectedIndex == 0)
                BackColor = Color.Red; 
            if (comboBox1.SelectedIndex == 1)
                BackColor = Color.Blue;
            if (comboBox1.SelectedIndex == 2)
                BackColor = Color.Purple;
            if (comboBox1.SelectedIndex == 3)
                BackColor = Color.Green;
            if (comboBox1.SelectedIndex == 4)
                BackColor = Color.Yellow;
            if (comboBox1.SelectedIndex == 5)
                BackColor = Color.Orange;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            
        }
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox2.SelectedIndex == 0)
                this.textBox1.ForeColor = Color.Red;
            if (comboBox2.SelectedIndex == 1)
                this.textBox1.ForeColor = Color.Blue;
            if (comboBox2.SelectedIndex == 2)
                this.textBox1.ForeColor = Color.Purple;
            if (comboBox2.SelectedIndex == 3)
                this.textBox1.ForeColor = Color.Green;
            if (comboBox2.SelectedIndex == 4)
                this.textBox1.ForeColor = Color.Yellow;
            if (comboBox2.SelectedIndex == 5)
                this.textBox1.ForeColor = Color.Orange;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string W = textBox2.Text;
            string H = textBox2.Text;
            this.Width = Convert.ToInt32(W);
            this.Height = Convert.ToInt32(H);
        }

        private void name2_Click(object sender, EventArgs e)
        {
            RegistryKey Key = Registry.CurrentUser.OpenSubKey(@"Software\NewRegKey");
            this.Height = (int)Key.GetValue("Длина");
            this.Width = (int)Key.GetValue("Ширина");
            textBox1.Text = Key.GetValue("Текст").ToString();
            int color = (int)Key.GetValue("Цвет фона");
            int color1 = (int)Key.GetValue("Цвет текста");
            this.BackColor = Color.FromArgb(color);
            this.textBox1.ForeColor = Color.FromArgb(color1);


        }

        private void button2_Click(object sender, EventArgs e)
        {
            RegistryKey Key = Registry.CurrentUser.CreateSubKey(@"Software\NewRegKey");
            Key.SetValue("Длина", this.Height);
            Key.SetValue("Ширина", this.Width);
            int color = this.BackColor.ToArgb();
            int color1 = this.textBox1.ForeColor.ToArgb();
            Key.SetValue("Цвет фона", color);
            Key.SetValue("Цвет текста", color1);
            Key.SetValue("Текст", textBox1.Text);
        }
    }
}
