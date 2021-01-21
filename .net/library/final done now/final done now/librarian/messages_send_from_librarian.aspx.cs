using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

namespace final_done_now.librarian
{
    public partial class messages_send_from_librarian : System.Web.UI.Page
    {
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");
        string username = "", msg = "";
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["librarian"] == null)
            {
                Response.Redirect("login.aspx");
            }
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            username = Request.QueryString["username"].ToString();
            msg = Request.QueryString["msg"].ToString();

            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "insert into messages values('librarian', '" + username.ToString() + "', '" + msg.ToString() + "', 'no')";
            cmd.ExecuteNonQuery();
        }
    }
}