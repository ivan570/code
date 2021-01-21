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
    public partial class student_display_all_books : System.Web.UI.Page
    {
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");
        protected void Page_Load(object sender, EventArgs e)
        {
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            if (Session["student"] == null)
            {
                Response.Redirect("student_login.aspx");
            }
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from ibooks";
            cmd.ExecuteNonQuery();
            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);

            r1.DataSource = dt;
            r1.DataBind();
        }
        public string checkvideo(object myvalue, object id)
        {
            if (myvalue == null)
            {
                return "not available";
            }
            else
            {
                myvalue = "../librarian/" + myvalue.ToString();
                return "<a href='" + myvalue.ToString() + "' style='color:green'> view video</a>";
            }
        }
        public string checkpdf(object myvalue1, object id1)
        {
            if (myvalue1 == null)
            {
                return "not available";
            }
            else
            {
                myvalue1 = "../librarian/" + myvalue1.ToString();
                return "<a href = '" + myvalue1.ToString() + "' style = 'color:green' > view pdf</a>";
            }
        }

    }
}