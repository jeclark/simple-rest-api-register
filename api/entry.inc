<?php

class entryAPI extends simpleAPI {

  public $smartClass = 'entry';

  public function getTotalsByMonth() {
    global $user, $login;
    $sql = "SELECT tag, entrydate, SUM(amount) as total FROM entries WHERE tag IN ('groceries', 'utilities', 'entertainment', 'gas', 'woodworking', 'restaurant') GROUP BY tag, DATE_FORMAT(entrydate, '%Y-%m') ORDER BY tag, entrydate DESC";
    //$sql = "SELECT tag, entrydate, SUM(amount) as total FROM entries GROUP BY tag, DATE_FORMAT(entrydate, '%Y-%m')";
    //$sql = "SELECT FROM `entries`";
    //$sql = "select * from entries where id >= 0";
    //$this->f->query("SET GLOBAL sql_mode='', SESSION sql_mode=''");
    $res = $this->f->query($sql);
    $this->debug['sql'] = $sql;
    if (is_object($res)) {
      $this->response['success'] = true;
      $this->response['data'] = array();
      while ($row = $res->fetch()) {
        $data = $row->toArray();
        $this->response['data'][] = $data;
      }
    } else {
      $this->response['success'] = false;
      $this->response['error'] = $this->f->error;
    }

  }

}
?>
