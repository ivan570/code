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
    public partial class returnbook : System.Web.UI.Page
    {
        int id = 0;
        string books_isbn = "";
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");
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

            id = Convert.ToInt32(Request.QueryString["id"].ToString());

            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "update issue_books set is_books_return ='yes', books_returned_date='" + DateTime.Now.ToString("yyyy/MM/dd") + "' where id='" + id + " '";
            cmd.ExecuteNonQuery();

            SqlCommand cmd1 = con.CreateCommand();
            cmd1.CommandType = CommandType.Text;
            cmd1.CommandText = "select * from issue_books where id='" + id + "' ";
            cmd1.ExecuteNonQuery();
            DataTable dt1 = new DataTable();
            SqlDataAdapter da1 = new SqlDataAdapter(cmd1);
            da1.Fill(dt1);

            foreach(DataRow dr1 in dt1.Rows)
            {
                books_isbn = dr1["books_isbn"].ToString();
            }

            SqlCommand cmd2 = con.CreateCommand();
            cmd2.CommandType = CommandType.Text;
            cmd2.CommandText = "update ibooks set available_qty=available_qty+1 where books_isbn='" + books_isbn.ToString() + "'";

            cmd2.ExecuteNonQuery();

            Response.Redirect("return_book.aspx");
        }
    }
}