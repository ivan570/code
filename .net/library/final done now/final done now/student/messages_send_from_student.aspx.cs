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
    public partial class messages_send_from_student : System.Web.UI.Page
    {
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");
        string username = "", msg = "";
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
            username = Session["student"].ToString();
            msg = Request.QueryString["msg"].ToString();

            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "insert into messages values('"+username.ToString()+"', 'librarian', '" + msg.ToString() + "', 'no')";
            cmd.ExecuteNonQuery();
        }
    }
}