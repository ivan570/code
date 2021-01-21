using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

namespace final_done_now.student
{
    public partial class student : System.Web.UI.MasterPage
    {
        int count = 0;
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");
        protected void Page_Load(object sender, EventArgs e)
        {
            if (con.State == ConnectionState.Open)
            {
                con.Close();
            }
            con.Open();
            if (Session["student"] == null)
            {
                Response.Redirect("student_login.aspx");
            }
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from messages where dusername='" + Session["student"].ToString() + "' and placed='no'";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            count = Convert.ToInt32(dt.Rows.Count.ToString());
            notification1.Text = count.ToString();
            notification2.Text = count.ToString();
            r1.DataSource = dt;
            r1.DataBind();
        }
        public string get20char(object myvalue)
        {
            string a = Convert.ToString(myvalue.ToString());
            if (a.Length < 20)
                return a;
            else
                return (a.Substring(0, 17) + "...");
        }
    }
}