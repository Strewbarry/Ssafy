<template>
  <div>
    <h1>Detail</h1>
    <div>여기는 {{id}}의 detail페이지 입니다</div>
  </div>
</template>

<script>
export default {
  data(){
    return{
      id:null,
    }
  },
  created(){
    this.id = this.$route.params.id;
  }
}
</script>

<style>

</style>