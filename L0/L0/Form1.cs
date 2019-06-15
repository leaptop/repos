using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace L0
{
    public partial class Form1 : Form
    {
        public int n;
        public int m;
        int[,] mas;
        public Form1()
        {
            InitializeComponent();
        }

        private void toolStripTextBox1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ФИО: Алексеев С.В. \nГруппа:ИП-712");
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
        public char[] arr  = new char [10];
         
        private void button1_Click(object sender, EventArgs e)
        {
            arr[0] = 'a'; arr[1] = 'b'; arr[2] = 'c'; arr[3] = 'd'; arr[4] = 'e'; arr[5] = 'f';
            n = Convert.ToInt32(numericUpDown1.Value);

            Random rand = new Random();
            if (n != 0)
            {
                dataGridView1.RowCount = n;
                dataGridView1.ColumnCount = n;
                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;

                 mas = new int[n, n];
                int i, j;
                for (i = 0; i < n; ++i)
                {
                    dataGridView1.Rows[i].HeaderCell.Value = arr[i].ToString();
                    for (j = 0; j < n; ++j)
                    {
                        dataGridView1.Columns[j].HeaderCell.Value = arr[j].ToString();
                        mas[i, j] = rand.Next(2);
                        dataGridView1.Rows[i].Cells[j].Value = mas[i, j];

                    }
                }
                   
                button2.Enabled = true;
                maxToolStripMenuItem.Enabled = true;
            }
            else
            {
                MessageBox.Show("N и M не могут быть нулевыми");
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            int[] mas = new int[n];
            int max;
            int i, j;
            for (i = 0; i < n; ++i)
            {
                mas[i] = Convert.ToInt32(dataGridView1.Rows[i].Cells[0].Value);
                for (j = 0; j < n; ++j)
                {
                    max = Convert.ToInt32(dataGridView1.Rows[i].Cells[j].Value);
                    if (max > mas[i])
                        mas[i] = max;
                }
            }
            dataGridView2.RowCount = n;
            dataGridView2.ColumnCount = 1;
            for (i = 0; i < n; ++i)
                dataGridView2.Rows[i].Cells[0].Value = mas[i];
            button2.Enabled = true;
            maxToolStripMenuItem.Enabled = true;//стрип меню - главное меню
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void startToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void sizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 f = new Form2();
            f.Owner = this;
            f.ShowDialog();
        }





        private void dataGridView1_CellValuePushed(object sender, DataGridViewCellValueEventArgs e)
        {//здесь происходит интерактивное изменеие ячеек
            int j = e.ColumnIndex;
            int i = e.RowIndex;
            mas[i, j] = Convert.ToInt32(e.ToString());
        }
        public void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {

        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void dataGridView1_CellValueChanged(object sender, DataGridViewCellEventArgs e)
        {//этот метод - не то, что нужно  

        }

        public void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }



    }
}
